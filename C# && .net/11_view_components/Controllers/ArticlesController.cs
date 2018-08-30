using System;
using Microsoft.AspNetCore.Mvc;
using System.Linq;
using Models;

namespace Example.Controllers
{
    public class ArticlesController : Controller
    {
        private NewsDbContext db;

        public ArticlesController(NewsDbContext db)
        {
            this.db = db;
        }

        public IActionResult Index(int? id)
        {
            // Show a single article if an id is given
            if (id != null)
            {
                var article = db.Articles.First(a => a.Id == id);

                if (article == null)
                    return NotFound();

                return View("Detail", article);
            }

            // If no article is given show all using the Index.cshtml view.
            // This view uses the view component so it fetches its own data.
            return View();
        }
    }
}
