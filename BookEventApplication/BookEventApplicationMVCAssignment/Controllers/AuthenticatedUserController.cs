using BusinessLogics;
using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Security.Principal;
using System.Web;
using System.Web.Mvc;



namespace BookEventApplicationMVCAssignment.Controllers
{
    [Authorize]
    public class AuthenticatedUserController : Controller
    {


        // GET: AuthenticatedUser
        public ActionResult Loggedin()
        {
            UserBL userBL = new UserBL();
            string name = User.Identity.Name;
            if (userBL.GetUserType(name) == "Admin")
            {
                return RedirectToAction("Admin", "AuthenticatedUser");
            }
           

            return View();
        }



        public ActionResult Admin()
        {
            return View();
        }


        public ActionResult MyEvents()
        {
            if (ModelState.IsValid)
            {
                string name = User.Identity.Name;
                UserBL userBL = new UserBL();
                EventsBL eventsBL = new EventsBL();

                if (userBL.GetUserType(name) == "Admin")
                {
                    eventsBL.GetAllEvents();
                    return View(eventsBL.GetAllEvents());

                }
               
                int Id = userBL.GetUserId(name);
                return View(userBL.GetEvents(Id));
            }

            return View();
        }



     
        public ActionResult EventsInvitedTo()
        {
            if (ModelState.IsValid)
            {
                string name = User.Identity.Name;
                UserBL userBL = new UserBL();
                EventsBL eventsBL = new EventsBL();
                string email=userBL.GetUserEmail(name);
                return View(eventsBL.EventsInvitedTo(email));

            }
                return View();
        }


        public ActionResult Details(int id)
        {
            EventsBL eventsBL = new EventsBL();
            
            return View(eventsBL.GetThisEvents(id));
        }




        [HttpGet]
        public ActionResult CreateEvents()
        {
            return View();
        }
        [HttpPost]
        public ActionResult CreateEvents(EventsBO eventsBO)
        {

            if (ModelState.IsValid)
            {
                string name = User.Identity.Name;

                UserBL userBL = new UserBL();
                EventsBL eventsBL = new EventsBL();
                int Id = userBL.GetUserId(name);
                string result = eventsBL.EventAdder(eventsBO, Id,name);
                return RedirectToAction("CreatedEvent", "AuthenticatedUser");

            }
            ModelState.AddModelError("", "There is some error in the event creation");
            return View();

        }


        public ActionResult CreatedEvent()
        {
            return View();
        }
        [HttpGet]
        public ActionResult Edit(int Id)
        {
            EventsBL eventsBL = new EventsBL();
            return View(eventsBL.EventsEditor(Id));

        }


        [HttpPost]
        public ActionResult Edit(EventsBO eventsBO)
        {

            if (ModelState.IsValid)
            {
                EventsBL eventsBL = new EventsBL();
                string result = eventsBL.UpdateEvents(eventsBO);
                if (result == "Data Successfully Added")
                {
                    return RedirectToAction("CreatedEvent", "AuthenticatedUser");

                }

            }
            ModelState.AddModelError("", "There is some error in the event updation");
            return View();

           

        }
    }
}