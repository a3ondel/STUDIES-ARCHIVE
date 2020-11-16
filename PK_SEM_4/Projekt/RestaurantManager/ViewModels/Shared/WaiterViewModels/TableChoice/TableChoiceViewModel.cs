using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Documents;
using System.Windows.Forms;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Views.WaiterViews;

namespace RestaurantManager.ViewModels.Shared.WaiterViewModels.TableChoice
{
    public sealed class TableChoiceViewModel : SharedDataViewModel<TableChoiceView>
    {
        //event passed to selected table and activecontroller
        public event EventHandler<TableModel> TableChanged;

        #region ListViewBinding
        //This selection is used for notifing and updating ActiveOrderController and SelectedTable
        //And Binding ListView inside ViewLink (TableChoiceView) 
        private TableModel _selectedItem;
        public TableModel SelectedItem
        {
            get => _selectedItem;
            set
            {
                _selectedItem = value;
                SharedData.IsTableSelected = true;
                TableChanged?.Invoke(null, _selectedItem);
            }
        }
        public ObservableCollection<TableModel> ActiveTablelist
        {
            get => SharedData.TablesCollection;
            set
            {
                SharedData.TablesCollection = value;
                OnPropertyChanged();
            }
        }
        private string _addTableText = "";
        public string AddTableText
        {
            get => _addTableText;
            set => OnPropertyChanged(ref _addTableText, value);
        }
        #endregion

        #region Commands -AddTableCommand
        //private Regex notNumbersRegex=new Regex(@"\D");

        private enum VCommands
        {
            AddTable
        }
        public CoreCommand AddTableCommand
        {
            get => GetVoidCommand(VCommands.AddTable);
            set => SetVoidCommand(VCommands.AddTable, ref value);
        }
        private void AddTable()
        {
            //Do nothing if there is no name
            if (string.IsNullOrEmpty(AddTableText))
            {
                MessageBox.Show("Type number of table first", "Information", MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
                return;
            }

            //instead of regex
            if (int.TryParse(AddTableText, out int resaultId))
            {
                TableModel tmpTable = new TableModel(resaultId, AddTableText);
                var tmp = SharedData.TablesCollection.ToList().Find((x) => x._Id == tmpTable._Id);

                if (tmp == null)
                {
                    //adding table to list (coppy const)
                    SharedData.TablesCollection.Add(tmpTable);
                }
                else
                {
                    MessageBox.Show($"Close Table before adding it again", "Close already opened table",
                        MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            else
            {
                MessageBox.Show("Only numbers are accepted", "Information", MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }

        }
        #endregion
        //Text for binding in this ViewLink (TableChoiceview)

        #region Ctor

        public TableChoiceViewModel(TableChoiceView view) : base(view)
        {
            OnStartup();
        }
        #endregion

        #region Inits -atm only inits addtablecommand

        private void OnStartup()
        {

            InitCommands();

        }

        private void InitCommands()
        {
            AddTableCommand = new CoreCommand(AddTable);
        }
        #endregion
    }
}
