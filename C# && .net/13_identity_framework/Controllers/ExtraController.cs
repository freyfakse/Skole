using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Example.Data;
using Example.Models;

namespace Example.Controllers
{
    public class ExtraController : Controller
    {
        private ApplicationDbContext db;
        private UserManager<ApplicationUser> um;
        private RoleManager<IdentityRole> rm;
        
        // Dependency inject both the db context and the user manager for use in actions
        public ExtraController(ApplicationDbContext db, UserManager<ApplicationUser> userManager, RoleManager<IdentityRole> roleManager)
        {
            this.db = db;
            this.um = userManager;
            this.rm = roleManager;
        }

        // Allow anonymous access (default)
        [AllowAnonymous]
        public IActionResult Index()
        {
            ViewBag.Name = "Anonymous";

            // Shows how to retrieve the ApplicationUser object
            if (User.Identity.IsAuthenticated)
            {
                var user = um.FindByNameAsync(User.Identity.Name).Result;
                ViewBag.Name = user.UserName;
            }

            return View();
        }

        // Allow only logged in users
        [Authorize]
        public IActionResult Users()
        {
            ViewBag.Name = "Anonymous";

            // Shows how to retrieve the ApplicationUser object
            if (User.Identity.IsAuthenticated)
            {
                var user = um.FindByNameAsync(User.Identity.Name).Result;
                ViewBag.Name = user.UserName;
            }


            return View();
        }

        // Allow only logged in administrators
        [Authorize(Roles="Admin")]
        public IActionResult Administrators()
        {
            ViewBag.Name = "Anonymous";

            // Shows how to retrieve the ApplicationUser object
            if (User.Identity.IsAuthenticated)
            {
                var user = um.FindByNameAsync(User.Identity.Name).Result;
                ViewBag.Name = user.UserName;
            }

            return View();
        }
    }
}
