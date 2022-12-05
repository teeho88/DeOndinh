using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO.Ports;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace TestUartIMU50
{
    class MainViewModel:ViewModelBase
    {
        private SerialPort mySerialPort;
        public MainViewModel()
        {
            ListBaud = new ObservableCollection<int> { 2400, 4800, 9600, 19200, 115200 };
            ListCom = new ObservableCollection<string>(SerialPort.GetPortNames());
            TextToSend = "";
            Baud = 9600;
            ConBT = new RelayCommand(x =>
            {
                mySerialPort = new SerialPort();
                mySerialPort.PortName = Port;
                mySerialPort.BaudRate = Baud;
                mySerialPort.DataReceived += DataReceivedHandler;
                mySerialPort.Open();
                MessageBox.Show("Connected");
            });
            SendBT = new RelayCommand(x =>
            {
                byte[] byteArr = BigInteger.Parse(TextToSend, System.Globalization.NumberStyles.HexNumber).ToByteArray().Reverse().ToArray();
                mySerialPort.Write(byteArr, 0, byteArr.Length);
            });
            ClearBT = new RelayCommand(x =>
            {
                TextRespond = "";
            });

        }

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            string s = mySerialPort.ReadExisting();
            TextRespond += s;
        }

        public ObservableCollection<string> ListCom { get; set; }
        public string Port { get; set; }
        public ObservableCollection<int> ListBaud { get; set; }
        public int Baud { get; set; }
        public string TextToSend { get; set; }
        private string textRespond;
        public string TextRespond { get => textRespond; set => SetProperty(ref textRespond, value); }
        public RelayCommand ConBT { get; set; }
        public RelayCommand SendBT { get; set; }
        public RelayCommand ClearBT { get; set; }
    }
}
