using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace Example.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
        
        [HttpGet]
        public IActionResult About()
        {
            ViewData["Message"] = "Your application description page.";

            Models.Student s = new Models.Student();

            s.FirstName = "Christian";
            s.LastName = "Auby";
            s.Subscribe = true;

            // Send the model object to the view
            return View(s);
        }

        [HttpPost]
        public IActionResult About(Models.Student student)
        {
            ViewData["Message"] = "Your application description page.";

            // Verify the model (based on the rules in the model)
            if (ModelState.IsValid)
            {
                Console.WriteLine("Model is valid!");
            }
            else
            {
                Console.WriteLine("Model is invalid!");
            }

            Console.WriteLine("Got data: " + student.FirstName + " " + student.LastName);

            return View();
        }

        public IActionResult List()
        {
            // Create a list of students
            var students = new List<Models.Student>();
            var s1 = new Models.Student();
            s1.FirstName = "First1";
            s1.LastName = "Last1";

            var s2 = new Models.Student();
            s2.FirstName = "First2";
            s2.LastName = "Last2";

            students.Add(s1);
            students.Add(s2);

            // Send the student list to the view
            return View(students);
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
