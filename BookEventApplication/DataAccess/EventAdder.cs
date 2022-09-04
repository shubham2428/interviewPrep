using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class EventAdder
    {
        private BookEventContext bookEventContext;
        public EventAdder()
        {
            bookEventContext = new BookEventContext();
        }
        public string AddEvent(EventsBO eventsBO,int id,string name)
        {
            UserBO userBO = new UserBO();
            bookEventContext.Database.Log = Console.Write;

            EventsBO events = new EventsBO()
            {
                EventId=eventsBO.EventId,
                EventsCreatedById=id,
                EventsCreatedByName=name,
                NameOfTheEvent=eventsBO.NameOfTheEvent,
                TypeOfEvent=eventsBO.TypeOfEvent,
                TitleOfTheBook = eventsBO.TitleOfTheBook,
                DateOfTheEvent =eventsBO.DateOfTheEvent,
                Location=eventsBO.Location,
                StartTime=eventsBO.StartTime,
                Duration=eventsBO.Duration,
                AddPeople=eventsBO.AddPeople,
                Description =eventsBO.Description


            };
            bookEventContext.EventsBOs.Add(events);


            int returnValue = bookEventContext.SaveChanges();

            if (returnValue > 0)
            {
                return "Data Successfully Added";
            }
            return "There is some prblem in the connection";
        }
      
       
        
       

       

    }
}
