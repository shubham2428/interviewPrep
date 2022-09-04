using BookEventApplicationMVCAssignment.Models;
using BusinessLogics;
using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace BookEventApplicationMVCAssignment.Controllers
{
    public class HomeController : Controller
    {
        

        public ActionResult Index()
        {
            EventsBL eventsBL = new EventsBL();
            var futureEvents = eventsBL.GetFutureEvents();
            var pastEvents = eventsBL.GetPastEvents();
            var viewModel = new MyIndexViewModel();
            viewModel.PastEvents = pastEvents;
            viewModel.FutureEvents = futureEvents;
            return View(viewModel);
        }
        public ActionResult Details(int id)
        {
            EventsBL eventsBL = new EventsBL();

            return View(eventsBL.GetThisEvents(id));
        }
        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
        [HttpGet]
        public ActionResult Signup()
        {
            return View();

        }
        [HttpPost]
        public ActionResult Signup(UserBO userBO)
        {

            if (ModelState.IsValid)
            {
                UserBL userBL = new UserBL();
                string result= userBL.AddUser(userBO);
                if(result== "UserName already exists")
                {
                    ModelState.AddModelError("","UserName already exists");
                }
                else
                {
                    return RedirectToAction("Index");
                }
                

            }
            return View();

        }
        [HttpGet]
        public ActionResult Login()
        {
            return View();

        }
        [HttpPost]
        public ActionResult Login(UserBO userBO)
        {
            UserBL userBL = new UserBL();
            if(userBL.IsAuthenticatedUser(userBO))
            {
                
                FormsAuthentication.SetAuthCookie(userBO.UserName, false);
                return RedirectToAction("Loggedin", "AuthenticatedUser");
                
            }
            ModelState.AddModelError("", "Invalid Credintials");
            return View();
        }
        public ActionResult Logout()
        {
            FormsAuthentication.SignOut();
            return View();
        }
       

    }
}