using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Win32;
using System.IO;
using System.Diagnostics;

namespace appPlayerInfo
{
    public class clsPlayerinfo
    {
        private static clsPlayerinfo selfInstance = null;
        public static clsPlayerinfo getInstance
        {
            get
            {
                if (selfInstance == null) selfInstance = new clsPlayerinfo();
                return selfInstance;
            }
        }

        public clsPlayerinfo()
        { 
        }

        ~clsPlayerinfo()
        {            
        }

        public string GetFilePath(string sFilePath)
        {
            string sResult = "";

            try
            {
                int nIndex = sFilePath.LastIndexOf('\\');
                sResult = sFilePath.Substring(0, nIndex);
            }
            catch
            {
                sResult = "";
            }
            return sResult;
        }

        public string GetMOMODataInfo(string skey)
        {
            string strValue = "";
            try
            {
                RegistryKey Reg = Registry.CurrentUser.OpenSubKey("SOFTWARE\\NOXGAMES\\MOMO", true);
                if (Reg == null)
                    return "";

                strValue = Reg.GetValue(skey).ToString();
                Reg.Close();
            }
            catch
            {
                return "";
            }
            return strValue;
        }

        public bool Rundnplayer()
        {
            string sRunApp = string.Format("{0}\\dnplayer.exe", GetMOMODataInfo("InstallDir"));
            if (!File.Exists(sRunApp))
                return false;

            Process.Start(sRunApp);
            return true;
        }

        public string GetNoxDataInfo(string skey)
        {
            string strValue = "";
            try
            {
                RegistryKey Reg = Registry.LocalMachine.OpenSubKey("SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Nox", true);
                if (Reg == null)
                    return "";

                strValue = Reg.GetValue(skey).ToString();
                Reg.Close();
            }
            catch
            {
                return "";
            }
            return strValue;
        }
                

        public bool RunNoxplayer()
        {
            string sInstallPath = string.Format("{0}", GetNoxDataInfo("UninstallString"));
            string sRunApp = string.Format("{0}\\Nox.exe", GetFilePath(sInstallPath));

            if (!File.Exists(sRunApp))
                return false;

            Process.Start(sRunApp);
            return true;
        }


        public string GetMEmuDataInfo(string skey)
        {
            string strValue = "";
            try
            {
                RegistryKey Reg = Registry.LocalMachine.OpenSubKey("SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\MEmu", true);
                if (Reg == null)
                    return "";

                strValue = Reg.GetValue(skey).ToString();
                Reg.Close();
            }
            catch
            {
                return "";
            }
            return strValue;
        }


        public bool RunMEmuplayer()
        {
            string sInstallPath = string.Format("{0}", GetMEmuDataInfo("InstallLocation"));
            string sRunApp = string.Format("{0}\\MEmu\\MEmuConsole.exe", sInstallPath);

            if (!File.Exists(sRunApp))
                return false;

            Process.Start(sRunApp, "MEmu");
            return true;
        }
    }
}
