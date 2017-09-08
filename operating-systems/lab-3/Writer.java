// This file defines class "writer".

// This code uses
//      class Semaphore, from the java.util.concurrent package in Java 5.0 which defines the behaviour of a 
//                           semaphore, including acquire and release operations.
//      class Synch, which defines the semaphores and variables
//                   needed for synchronizing the readers and writers.
//      class RandomSleep, which defines the doSleep method.


public class Writer extends Thread {
  int myName;  // The variable myName stores the name of this thread.
               // It is initialized in the constructor for class Reader.

  RandomSleep rSleep;  // rSleep can hold an instance of class RandomSleep.



  // This is the constructor for class Writer.  It has an integer parameter,
  // which is the name that is given to this thread.
  public Writer(int name) {
    myName = name;  // copy the parameter value to local variable "MyName"
    rSleep = new RandomSleep();   // Create and instance of RandomSleep.
  }  // end of the constructor for class "Writer"



  public void run () {
    for (int I = 0;  I < 5; I++) {

      // Get permission to write
      System.out.println("Writer " + myName + " wants to write");
      
      // START WRITE
      
      try{
    	  Synch.mutex.acquire();
      }
      catch (Exception e){}
      
      if (Synch.mode != "idle")
	  {
		  Synch.wantToWrite++; // New writer waiting
		  Synch.mutex.release();
		  try{
			  Synch.writerSem.acquire(); // get writerSem
		  }
		  catch (Exception e){}
		  try{
			  Synch.mutex.acquire();
		  }
		  catch (Exception e){}
		  Synch.wantToWrite--; // New writer is no longer waiting
	  }
      else
      {
    	  try{
			  Synch.writerSem.acquire(); // if mode is idle we acquire writerSem in order to make sure its the only writer writing
		  }
		  catch (Exception e){}
      }
	  Synch.mode = "writing";
	  Synch.numberWriting++;
	  System.out.println("Writer " + myName + " is now writing");
	  Synch.mutex.release();
	  
      // Simulate the time taken by writing.
      rSleep.doSleep(1, 200);

      // END WRITE
      
      try{
    	  Synch.mutex.acquire();
      }
      catch (Exception e){}
      Synch.numberWriting--;
      System.out.println("Writer " + myName + " is finished writing");
	  if (Synch.wantToWrite > 0) // writers have priority
	  {
		  Synch.writerSem.release();
	  }
	  else if (Synch.wantToRead > 0) // releases enough readerSem's for readers in waiting
	  {
		  for (int i = 1; i <= Synch.wantToRead; i++)
		  {
			  Synch.readerSem.release();
		  }
		  Synch.mode = "reading";
	  }
	  else
	  {
		  Synch.mode = "idle"; // system is in idle if there is no one waiting
	  }
	  Synch.mutex.release();

      // Simulate "doing something else"
      rSleep.doSleep(1, 1000);
    } // end of "for" loop
  }  // end of "run" method
}  // end of class "Writer"
