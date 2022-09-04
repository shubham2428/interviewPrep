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
    public class AuthenticatedUserControllerTest
    {
        [TestMethod]
        public void Admin()
        {
            //Arrange
            AuthenticatedUserController controller = new AuthenticatedUserController();

            //Act
            ViewResult result = controller.Admin() as ViewResult;

            //Assert
            Assert.IsNotNull(result);
        }

    }
}
