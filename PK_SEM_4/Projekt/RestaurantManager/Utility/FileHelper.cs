using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Security.Cryptography;
using System.IO;
using System.Security.RightsManagement;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Markup;
using Newtonsoft.Json;
using RestaurantManager.Annotations;
using RestaurantManager.Models;


namespace RestaurantManager.Utility
{
    using UserType=UserModel.EUserType;

    public static class FileHelper
    {
        private static readonly JsonSerializerSettings JsonSerializeSettings = new JsonSerializerSettings { Formatting = Formatting.Indented };

        #region Outdated

        //public static List<UserModel> LoadUsersFromFile(string fileName)
        //{
        //    if(string.IsNullOrEmpty(fileName))
        //        return null;

        //    string jsonFileString = File.ReadAllText(fileName);

        //    return  JsonConvert.DeserializeObject<List<UserModel>>(jsonFileString, JsonSerializeSettings);
        //}


        
        //public static bool SaveUsersToFile(string fileName,List<UserModel> userliList)
        //{
        //    if (string.IsNullOrEmpty(fileName) || userliList == null)
        //        return false;

        //    string jsonFileString= JsonConvert.SerializeObject(userliList,Formatting.Indented);
        //    File.WriteAllText(fileName, jsonFileString);

        //    return true;
        //}

        //load from json file to list try catch 
        //public static List<T> ListFileReader<T>(string fileName)
        //{

        //    List<T> xList=new List<T>();
            

        //    if (string.IsNullOrEmpty(fileName))
        //        return null;

        //    string jsonFileString = File.ReadAllText(fileName);

        //    return JsonConvert.DeserializeObject<List<T>>(jsonFileString, JsonSerializeSettings);
        //}
        //load from json file to list

        #endregion

        public static T FileReader <T>(string fileName)
        {
            if (string.IsNullOrEmpty(fileName))
                throw new Exception($"File \"{fileName}\" cannot be open, or doesnt exist");

            var jsonString = "";
            try
            {
                jsonString = File.ReadAllText(fileName);
            }
            catch (Exception e)
            {

                throw new Exception($"File {fileName} is cannot be open or doesnt exist\nMore: {e.Message}");
            }
            
            return JsonConvert.DeserializeObject<T>(jsonString, JsonSerializeSettings);

        }

        public static bool FileWriter<T>(string fileName, T obj)
        {
            if (string.IsNullOrEmpty(fileName) || obj==null)
                    return false;

            try
            {
                var jsonString = JsonConvert.SerializeObject(obj, JsonSerializeSettings);
                File.WriteAllText(fileName, jsonString);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                return false;
            }
            return true;
        }

        
    }//
}
