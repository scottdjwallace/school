// This file defines class "Reader".

// This code uses
//      class Semaphore, from the java.util.concurrent package in Java 5.0 which defines the behaviour of a 
//                           semaphore, including acquire and release operations.
//      class Synch, which defines the semaphores and variables 
//                   needed for synchronizing the readers and writers.
//      class RandomSleep, which defines the doSleep method.


public class Reader extends Thread {
  int myName;  // The variable myName stores the name of this thread.
               // It is initialized in the constructor for class Reader.

  RandomSleep rSleep;  // rSleep can hold an instance of class RandomSleep.



  // This is the constructor for class Reader.  It has an integer parameter,
  // which is the name that is given to this thread.
  public Reader(int name) {
    myName = name;  // copy the parameter value to local variable "MyName"
    rSleep = new RandomSleep();  // Create an instance of RandomSleep.
  }  // end of the constructor for class "Reader"



  public void run () {
    for (int I = 0;  I < 5; I++) {
      System.out.println("Reader " + myName + " wants to read.  "
                         + "Beforehand, wantToRead is "  + Synch.wantToRead);
      
      // START READ
      
      try{
      	Synch.mutex.acquire();
      }
      catch(Exception e){}
      
      if (Synch.mode == "writing" || Synch.wantToWrite > 0) // we are currently writing and therefore readers must wait
	  {
		  Synch.wantToRead++;
		  Synch.mutex.release();
		  try{
			  Synch.readerSem.acquire();
		  }
		  catch (Exception e){}
		  try{
			  Synch.mutex.acquire();
		  }
		  catch (Exception e){}
		  Synch.wantToRead--;
	  }
      
      Synch.mode = "reading";
	  Synch.numberReading++; // new reader reading
      
      System.out.println("Reader " + myName + " is now reading.  "
                         + "wantToRead is " + Synch.wantToRead);
      Synch.mutex.release();

      // Simulate the time taken for reading
      rSleep.doSleep(1, 200);   
      
      // END READ

      try{
      	Synch.mutex.acquire();
      }
      catch(Exception e){}
      Synch.numberReading--; // done reading, so one less reading
      System.out.println("Reader " + myName + " is finished reading.  " 
              + "numberReading decremented to " + Synch.numberReading);
      if (Synch.numberReading == 0) // if all are done reading
	  {
		  if (Synch.wantToWrite > 0) // if there are writers waiting then they get to go
		  {
			  Synch.writerSem.release();
			  Synch.mode = "writing";
		  }
		  else
		  {
			  Synch.mode = "idle"; // system goes into idle with no one waiting
		  }
	  }
      
      Synch.mutex.release();


      // Simulate "doing something else".
      rSleep.doSleep(1, 1000);
    } // end of "for" loop
  }  // end of "run" method
}  // end of class "Reader"