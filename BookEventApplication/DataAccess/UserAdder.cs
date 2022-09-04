using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class UserAdder
    {
        private BookEventContext bookEventContext;
        public UserAdder()
        {
            bookEventContext = new BookEventContext();
        }
        public string AddUser(UserBO userBO)
        {
            bookEventContext.Database.Log = Console.Write;
            
            UserBO users = new UserBO()
            {
                UserID = userBO.UserID,
                UserName = userBO.UserName,
                Password = userBO.Password,
                EmailId=userBO.EmailId,
                TypeOfUser=userBO.TypeOfUser
            };
           
            bookEventContext.UserBOs.Add(users);


            int returnValue = bookEventContext.SaveChanges();
            
            if (returnValue > 0)
            {
               return "Data Successfully Added";
            }
            return "There is some prblem in the connection";
        }
    }
    }

