// This file defines class "Synch".  This class contains all the semaphores
// and variables needed to coordinate the instances of the Reader and Writer
// classes.  

import java.util.concurrent.*;

public class Synch 
{

  public static int wantToRead = 0; // number of readers waiting
  public static int wantToWrite = 0; // number of writers waiting
  public static int numberReading = 0; // number of readers reading
  public static int numberWriting = 0; // number of writers writing
  
  public static String mode = "idle"; // idle, reading, writing
  
  public static Semaphore mutex;
 
  public static Semaphore readerSem;
  public static Semaphore writerSem;
  
}  // end of class "Synch"