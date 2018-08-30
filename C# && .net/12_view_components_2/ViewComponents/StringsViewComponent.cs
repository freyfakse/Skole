using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace ViewComponents
{
    public class StringsViewComponent : ViewComponent
    {
        public async Task<IViewComponentResult> InvokeAsync(int count = 5, string search = null)
        {
            var strings = new List<string>()
            {
                "One",
                "Two",
                "three",
                "Four",
                "Five",
                "Six"
            };

            if (search != null)
            {
                strings = strings.Where(s => s.Contains(search)).ToList();
            }
            
            return View(strings.Take(count));
        }
    }
}
