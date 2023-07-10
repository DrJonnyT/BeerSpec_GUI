#include "pch.h"
#include "SerialManager.h"

SerialManager::SerialManager(String^ portName, int baudRate, RichTextBox^ sendCommandsTextBox, RichTextBox^ receivedCommandsTextBox)
{
    serialPort = gcnew SerialPort(portName, baudRate);
    sendCommandQueue = gcnew Queue<String^>();
    receivedCommandQueue = gcnew Queue<String^>();
    rtbSendCommands = sendCommandsTextBox;
    rtbReceivedCommands = receivedCommandsTextBox;
    serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(this, &SerialManager::DataReceivedHandler);
}

//Default constructor
SerialManager::SerialManager()
{
    serialPort = gcnew SerialPort();
}

void SerialManager::Open()
{
    if (!serialPort->IsOpen)
    {
        serialPort->Open();
    }
}

void SerialManager::Close()
{
    if (serialPort->IsOpen)
    {
        serialPort->Close();
    }
}

bool SerialManager::IsOpen()
{
    return serialPort->IsOpen;
}

void SerialManager::EnqueueSendCommand(String^ command)
{
    sendCommandQueue->Enqueue(command);
}

void SerialManager::ProcessReceivedCommands()
{
    while (receivedCommandQueue->Count > 0)
    {
        String^ command = receivedCommandQueue->Dequeue();

        // Check if the command starts with "@" and ends with "\n", i.e. it is a standard command coming from the Arduino
        if (command->StartsWith("@")) {
            // Process the received command as needed
            UpdateReceivedCommandsTextBox(command);
        }
    }
}

void SerialManager::SendQueuedCommands()
{
    while (sendCommandQueue->Count > 0)
    {
        String^ command = sendCommandQueue->Dequeue();
        if (serialPort != nullptr)
        {
            serialPort->WriteLine(command);
            UpdateSendCommandsTextBox(command);
        }
    }
}

void SerialManager::UpdateSendCommandsTextBox(String^ command)
{
    if (rtbSendCommands != nullptr)
    {
        //Remove whitespace from the ends
        command = command->Trim();

        //Scroll to the end of the richtextbox
        rtbSendCommands->SelectionStart = rtbSendCommands->Text->Length;
        rtbSendCommands->ScrollToCaret();

        //Add datetime to start and append to box
        String^ dateTimeNowStr = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
        rtbSendCommands->AppendText(dateTimeNowStr + ": " + command + Environment::NewLine);
    }
}

void SerialManager::UpdateReceivedCommandsTextBox(String^ command)
{
    if (rtbReceivedCommands != nullptr)
    {
        //Remove whitespace from the ends
        command = command->Trim();

        //Scroll to the end of the richtextbox
        rtbReceivedCommands->SelectionStart = rtbReceivedCommands->Text->Length;
        rtbReceivedCommands->ScrollToCaret();

        //Add datetime to start and append to box
        String^ dateTimeNowStr = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
        rtbReceivedCommands->AppendText(dateTimeNowStr + ": " + command + Environment::NewLine);
    }
}

void SerialManager::DataReceivedHandler(Object^ sender, SerialDataReceivedEventArgs^ e)
{
    if (serialPort != nullptr)
    {
        String^ receivedData = serialPort->ReadLine();
        receivedCommandQueue->Enqueue(receivedData);
    }
}

