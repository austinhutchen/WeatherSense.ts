
export function findday(counter) {
 const today = new Date();
 day = today.getDay();
 switch (day + counter) {
   case 0:
     return "Sunday";
   case 1:
     return "Monday";
   case 2:
     return "Tuesday";
   case 3:
     return "Wednesday";
   case 4:
     return "Thursday";
   case 5:
     return "Friday";
   case 6:
     return "Saturday";
 }
} 

export function searchAPI(city) {
// searches the given API for weather at city
var key = "76875c2ba9d949cbf7e9c0e76057de73";


}