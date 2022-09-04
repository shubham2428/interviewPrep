using BookEventApplicationMVCAssignment.Controllers;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Mvc;

namespace UnitTestProject1.Controller
{
    [TestClass]
    public class HomeControllerTest
    {
        [TestMethod]
        public void Contact()
        {
            //Arrange
            HomeController controller = new HomeController();

            //Act
            ViewResult result = controller.Contact() as ViewResult;

            //Assert
            Assert.IsNotNull(result);
        }
        [TestMethod]
        public void About()
        {
            //Arrange
            HomeController controller = new HomeController();

            //Act
            ViewResult result = controller.About() as ViewResult;

            //Assert
            Assert.AreEqual("Your application description page.",result.ViewBag.Message);
        }

       
    }

}
