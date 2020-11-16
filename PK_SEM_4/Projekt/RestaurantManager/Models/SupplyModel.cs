using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using RestaurantManager.DB;

namespace RestaurantManager.Models
{
    public sealed class SupplyModel : CountableDB
    {
        private int _normalUsage;

        public int NormalSize
        {
            get => _normalUsage;
            set => OnPropertyChanged(ref _normalUsage, value);
        }

        private string _countTag;
        public string CountTag
        {
            get => _countTag;
            set => OnPropertyChanged(ref _countTag, value);
        }

        public SupplyModel(int id, string name, double amount, int normalUsage, string countTag) : base(id, name, amount)
        {
            _normalUsage = normalUsage;
            _countTag = countTag;
        }

        

    }
}
