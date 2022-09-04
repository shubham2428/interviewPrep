using BookEventApplicationMVCAssignment.Controllers;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.MVC;

namespace BookEventApplicationUnitTest.Controllers
{
    [TestClass]
     public class HomeControllerTest
    {
        [TestMethod]
        public void Index()
        {
            //Arrange
            HomeController controller = new HomeController();

            //Act
            int  result = controller.Index() ;




        }
    }
}
