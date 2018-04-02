function validate()
{
   if( document.StudentRegistration.textnames.value == "" )
   {
     alert( "Please provide your Name!" );
     document.StudentRegistration.textnames.focus() ;
     return false;
   }



   if( document.StudentRegistration.address.value == "" )
   {
     alert( "Please provide your  Address!" );
     document.StudentRegistration.address.focus() ;
     return false;
   }

   var email = document.StudentRegistration.emailid.value;
   atpos = email.indexOf("@");
   dotpos = email.lastIndexOf(".");
   if (email == "" || atpos < 1 || ( dotpos - atpos < 2 ))
   {
     alert("Please enter correct email ID")
     document.StudentRegistration.emailid.focus() ;
     return false;
   }
   if( document.StudentRegistration.mobileno.value == "" ||
           isNaN( document.StudentRegistration.mobileno.value) ||
           document.StudentRegistration.mobileno.value.length != 10 )
   {
     alert( "Please enter a valid mobile No." );
     document.StudentRegistration.mobileno.focus() ;
     return false;
   }


   if( document.StudentRegistration.bankaccountnumber.value == "" ||
         isNaN( document.StudentRegistration.bankaccountnumber.value) ||
         document.StudentRegistration.bankaccountnumber.value.length != 5 )
  {
   alert( "Please enter a valid account No." );
   document.StudentRegistration.bankaccountnumber.focus() ;
   return false;
  }
  return( true );
}
