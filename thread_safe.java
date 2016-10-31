import java.util.concurrent.*;   /* needed for Semaphore class */

class MonitorT {
   private int contents; 
   boolean consumer_attached = true;
   private Semaphore tokenout = new Semaphore(0,true);
   private Semaphore tokenin  = new Semaphore(1,true);

   // tokenin starts out unblocked, tokenout starts out blocked
   public int get() throws InterruptedException {
      tokenout.acquire();  // Consumer blocked until producer has put
      tokenin.release();   // Tell the producer a token has been taken
      return contents;     // Take the token
   }

   public void put(int value) throws InterruptedException {
      tokenin.acquire();   // Producer blocked until consumer has taken token
      contents = value;    // Put the token into memory
      tokenout.release();  // Tell the consumer the token is put
   }
}

class ProducerT extends Thread {
   private MonitorT monitor;
   private int number;

   public ProducerT(MonitorT c, int number) {
      monitor = c;
      this.number = number;
   }

   public void run() {
      for (int i = 0; monitor.consumer_attached ; i++) {
         System.out.println("Producer #" + number + " will put: " + i);
         try { monitor.put(i); } catch (InterruptedException e) {
	    System.out.println("Forget about it");
	 }
         System.out.println("Producer #" + number + " has put: " + i);
      }
      System.out.println("Producer #" + number + " exiting");
   }
}

class ConsumerT extends Thread {
   private MonitorT monitor;
   private int number;

   public ConsumerT(MonitorT c, int number) {
      monitor = c;
      this.number = number;
   }

   public void run() {
      int value = 0;
      for (int i = 0; i < 10; i++) {
         System.out.println("\t\t\tConsumer #"+number+" will get a value");
         try { value = monitor.get(); } catch (InterruptedException e) {
	    System.out.println("Forget about it");
	 }
         System.out.println("\t\t\tConsumer #"+number+" got: "+value);
      }
      monitor.consumer_attached = false;
      System.out.println("Consumer #" + number + " exiting");
   }
}

class RunnerT {
   public void runIt () {
      try { Thread.sleep(200); } catch (Exception e) { }
      MonitorT monitor = new MonitorT();
      ProducerT p1 = new ProducerT(monitor, 1);
      ConsumerT c1 = new ConsumerT(monitor, 2);
      p1.start();
      c1.start();
   }
}

public class thread_safe {
   public static void main (String args[]) {
      (new RunnerT()).runIt();
   }
}

