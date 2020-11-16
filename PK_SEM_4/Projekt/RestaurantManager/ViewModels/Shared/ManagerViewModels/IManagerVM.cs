using RestaurantManager.Core;

namespace RestaurantManager.ViewModels.Shared.ManagerViewModels
{
    public interface IManagerVM
    {
        CoreCommand OptAddCommand { get; set; }
        CoreCommand OptEditCommand { get; set; }
        CoreCommand OptDelCommand { get; set; }

    }
}
