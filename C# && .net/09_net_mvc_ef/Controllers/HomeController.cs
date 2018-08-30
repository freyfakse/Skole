using Microsoft.AspNetCore.Mvc;

using Example.Models;

namespace Example.Controllers
{
    public class HomeController : Controller
    {
        private BloggingContext db;

        public HomeController(BloggingContext db)
        {
            this.db = db;
        }
        public IActionResult Index()
        {
            // Add a blog every time the main page is visited
            var blog = new Blog();
            blog.Url = "http://www.nrk.no/";

            db.Blogs.Add(blog);
            db.SaveChanges();

            return View();
        }

        public IActionResult About()
        {
            ViewData["Message"] = "Your application description page.";

            return View();
        }

        public IActionResult Contact()
        {
            ViewData["Message"] = "Your contact page.";

            return View();
        }

        public IActionResult Error()
        {
            return View();
        }
    }
}
