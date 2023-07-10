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
        // Process the received command as needed
        UpdateReceivedCommandsTextBox(command);
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
        rtbSendCommands->AppendText(command + Environment::NewLine);
    }
}

void SerialManager::UpdateReceivedCommandsTextBox(String^ command)
{
    if (rtbReceivedCommands != nullptr)
    {
        rtbReceivedCommands->AppendText(command + Environment::NewLine);
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

