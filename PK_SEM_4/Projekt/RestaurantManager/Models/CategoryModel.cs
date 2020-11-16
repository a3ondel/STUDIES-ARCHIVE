using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.DB;

namespace RestaurantManager.Models
{
    public sealed class CategoryModel : NameDB
    {
        private string _imgPath;
        public string ImgPath
        {
            get => _imgPath;
            set => OnPropertyChanged(ref _imgPath,value);
        }

        
        //init to prevent null
        private ObservableCollection<MealModel> _categoryMealsCollection=new ObservableCollection<MealModel>();
        public ObservableCollection<MealModel> CategoryMealsCollection;


        public CategoryModel(int id, string name, string imgPath) : base(id, name)
        {
            _imgPath = imgPath;
        }


        public CategoryModel(int id, string name, string imgPath, ObservableCollection<MealModel> categoryMealsCollection=null) : base(id, name)
        {
            _imgPath = imgPath;
            CategoryMealsCollection = categoryMealsCollection;
        }


        public CategoryModel(string imgPath, ObservableCollection<MealModel> categoryMealsCollection)
        {
            _imgPath = imgPath;
            CategoryMealsCollection = categoryMealsCollection;
        }


        //base constructor used by deserialization
        public CategoryModel(){}
    }
}
