using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

using Example.Models;

// For more information on enabling MVC for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace Example.Controllers
{
    public class ExampleController : Controller
    {
        [HttpGet]
        public IActionResult Index()
        {
            return View(new FormModel());
        }

        [HttpPost]
        public IActionResult Index(FormModel data)
        {
            Console.WriteLine(data.Email);
            Console.WriteLine(data.Password);
            Console.WriteLine(data.Check);

            return View(data);
        }
    }
}
