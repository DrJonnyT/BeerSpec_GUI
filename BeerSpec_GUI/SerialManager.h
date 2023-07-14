#pragma once

#include <iostream>
#include <string>
#include <queue>
//#include <Windows.h>
#include "MeasClass.h"

using namespace System;
using namespace System::IO::Ports;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class SerialManager
{
private:
    SerialPort^ serialPort;
    Queue<String^>^ sendCommandQueue;
    Queue<String^>^ receivedCommandQueue;
    RichTextBox^ rtbSendCommands;
    RichTextBox^ rtbReceivedCommands;

public:
    SerialManager(String^ portName, int baudRate, RichTextBox^ sendCommandsTextBox, RichTextBox^ receivedCommandsTextBox);
    SerialManager();
    void Open();
    void Close();
    bool IsOpen();
    void EnqueueSendCommand(String^ command);
    void ProcessReceivedCommands(MeasClass^ meas);
    void SendQueuedCommands();

private:
    void UpdateSendCommandsTextBox(String^ command);
    void UpdateReceivedCommandsTextBox(String^ command);
    void DataReceivedHandler(Object^ sender, SerialDataReceivedEventArgs^ e);
};
