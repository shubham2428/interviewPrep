using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class EventsUpdator
    {
        public string UpdateEvents(EventsBO eventsBO)
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            bookEventContext.Entry(eventsBO).State = System.Data.Entity.EntityState.Modified;
            int returnValue = bookEventContext.SaveChanges();
            if (returnValue > 0)
            {
                return "Data Successfully Added";
            }
            return "There is some problem in the connection";


        }

    }
}
