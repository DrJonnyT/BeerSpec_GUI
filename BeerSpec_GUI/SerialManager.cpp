#include "pch.h"
#include "SerialManager.h"
#include "MeasClass.h"

SerialManager::SerialManager(String^ portName, int baudRate, RichTextBox^ sendCommandsTextBox, RichTextBox^ receivedCommandsTextBox)
{
    m_serialPort = gcnew SerialPort(portName, baudRate);
    m_sendCommandQueue = gcnew Queue<String^>();
    m_receivedCommandQueue = gcnew Queue<String^>();
    m_rtbSendCommands = sendCommandsTextBox;
    m_rtbReceivedCommands = receivedCommandsTextBox;
    m_serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(this, &SerialManager::DataReceivedHandler);
}

//Default constructor
SerialManager::SerialManager()
{
    m_serialPort = gcnew SerialPort();
}

void SerialManager::Open()
{
    if (!m_serialPort->IsOpen)
    {
        m_serialPort->Open();
    }
}

void SerialManager::Close()
{
    if (m_serialPort->IsOpen)
    {
        m_serialPort->Close();
    }
}

//Check it's communicating with the instrument
bool SerialManager::Check()
{
    if (this->IsOpen())
    {
        //Send the check command
        this->EnqueueSendCommand("#CHECKSERIAL");
        this->SendQueuedCommands();
        System::Threading::Thread::Sleep(500);

        //If no response, serial not working
        if (m_receivedCommandQueue->Count == 0)
        {
            return false;
        }
        else
        {
            String^ command = m_receivedCommandQueue->Dequeue();
            if (command->StartsWith("@SERIALOK"))
            {
                //The only correct response
                return true;
            }
            else
            {
                return false;
            }
        }

    }
    else
    {
        return false;
    }
}

bool SerialManager::IsOpen()
{
    return m_serialPort->IsOpen;
}

void SerialManager::EnqueueSendCommand(String^ command)
{
    m_sendCommandQueue->Enqueue(command);
}

void SerialManager::ProcessReceivedCommands(MeasClass^ meas)
{
    while (m_receivedCommandQueue->Count > 0)
    {
        String^ command = m_receivedCommandQueue->Dequeue();

        // Check if the command starts with "@" and ends with "\n", i.e. it is a standard command coming from the Arduino
        if (command->StartsWith("@"))
        {
            //Read extinction data
            if (command->StartsWith("@EXT"))
            {
                meas->ReadExtFromString(command);
                meas->MeasTime = DateTime::Now.ToString();
                
            }

            //Read scattering data
            if (command->StartsWith("@SCA"))
            {
                meas->ReadScaFromString(command);
                meas->MeasTime = DateTime::Now.ToString();

            }

            

            // Update the received command box afterwards
            UpdateReceivedCommandsTextBox(command);
        }
    }
}

void SerialManager::SendQueuedCommands()
{
    while (m_sendCommandQueue->Count > 0)
    {
        String^ command = m_sendCommandQueue->Dequeue();
        if (m_serialPort != nullptr)
        {
            m_serialPort->WriteLine(command);
            UpdateSendCommandsTextBox(command);
        }
    }
}

void SerialManager::UpdateSendCommandsTextBox(String^ command)
{
    if (m_rtbSendCommands != nullptr)
    {
        //Remove whitespace from the ends
        command = command->Trim();

        //Scroll to the end of the richtextbox
        m_rtbSendCommands->SelectionStart = m_rtbSendCommands->Text->Length;
        m_rtbSendCommands->ScrollToCaret();

        //Add datetime to start and append to box
        String^ dateTimeNowStr = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
        m_rtbSendCommands->AppendText(dateTimeNowStr + ": " + command + Environment::NewLine);
    }
}

void SerialManager::UpdateReceivedCommandsTextBox(String^ command)
{
    if (m_rtbReceivedCommands != nullptr)
    {
        //Remove whitespace from the ends
        command = command->Trim();

        //Scroll to the end of the richtextbox
        m_rtbReceivedCommands->SelectionStart = m_rtbReceivedCommands->Text->Length;
        m_rtbReceivedCommands->ScrollToCaret();

        //Add datetime to start and append to box
        String^ dateTimeNowStr = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
        m_rtbReceivedCommands->AppendText(dateTimeNowStr + ": " + command + Environment::NewLine);
    }
}

void SerialManager::DataReceivedHandler(Object^ sender, SerialDataReceivedEventArgs^ e)
{
    if (m_serialPort != nullptr)
    {
        String^ receivedData = m_serialPort->ReadLine();
        m_receivedCommandQueue->Enqueue(receivedData);
    }
}

