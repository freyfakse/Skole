using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Linq;
using System.Collections.Generic;

using Example.Models;

namespace Example.Controllers
{
    public class HomeController : Controller
    {
        private StudentDbContext db;

        public HomeController(StudentDbContext db)
        {
            this.db = db;
        }
        public IActionResult Index()
        {
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

        // Search and sorts student using the Linq method syntax
        public IActionResult StudentListMethod(string sort, string search)
        {
            // Start with all students (as a queryable, we want to do more with it)
            var students = db.Students.AsQueryable();

            // Filter if search is given
            if (search != null)
            {
                students = students.Where(s =>
                    s.FirstName.Contains(search) ||
                    s.LastName.Contains(search)
                );

                // Store the current search in the ViewBag so the view can use it
                ViewBag.Search = search;
            }

            // Perform sorting
            if (sort == "FirstName")
                students = students.OrderBy(s => s.FirstName);
            else
                students = students.OrderBy(s => s.LastName);

            // We use the Include() function to load related entities.
            // We do this last to fetch as little as possible.
            students = students.Include(s => s.Grades);

            // Send the result to the view as a list
            return View("StudentList", students.ToList());
        }

        public IActionResult StudentListQuery(string sort, string search)
        {
            // Start with all students (as a queryable, we want to do more with it)
            var students = db.Students.AsQueryable();

            // Filter if search is given
            if (search != null)
            {
                students =
                    from s in students
                    where s.FirstName.Contains(search) || s.LastName.Contains(search)
                    select s;

                // Store the current search in the ViewBag so the view can use it
                ViewBag.Search = search;
            }

            // Perform sorting
            if (sort == "FirstName")
                students =
                    from s in students
                    orderby s.FirstName
                    select s;
            else
                students =
                    from s in students
                    orderby s.LastName
                    select s;

            // We use the Include() function to load related entities.
            // We do this last to fetch as little as possible.
            students = students.Include(s => s.Grades);

            // Send the result to the view as a list
            return View("StudentList", students.ToList());
        }

        public IActionResult Error()
        {
            return View();
        }
    }
}
