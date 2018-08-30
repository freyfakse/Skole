using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Models;

namespace ViewComponents
{
    // Controller for the view component that shows a list of recent articles
    public class ArticlesList : ViewComponent
    {
        private NewsDbContext db;

        public ArticlesList(NewsDbContext db)
        {
            this.db = db;
        }

        // This function fetches data for the view component.
        // It is an async function so it can run in parallell with other async functions.
        public async Task<IViewComponentResult> InvokeAsync(int articleCount = 10)
        {
            /* The only difference between this and a regular controller is that we have
             * to use await together with ToListAsync(). We don't actually need to do
             * this as it works with ToList() just fine, but it removes a warning.
             */
            var articles = await db.Articles.Take(articleCount).ToListAsync();

            // Send the articles to the Views/Shared/Components/ArticlesList/Default.cshtml view
            return View(articles);
        }
    }
}
