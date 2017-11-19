import java.applet.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

/* <applet code=typ_unsafe_1.class width=90 height=22></applet> */

interface I {
   public int dbl ();
}

class A4 implements I {
   int number;
   
   public A4 (int n) { number = n; }
   public int dbl () { return number*2; }
   public String toString () { return String.valueOf(number); }
   public int answer () { return 42; }
}

class B4 implements I {
   String str;
   
   public B4 (String n) { str = n; }
   public int dbl () { return 2*Integer.parseInt(str); }
   public String toString () { return str; }
   // answer is missing here
}

// A Vector can hold different kinds of objects
// But then operating on an object taken from the vector
// may be problematic if the operation does not apply to
// the type of object.  In this example, the vector 
// is defined to hold only I objects and all I objects
// implement method dbl which returns an int.
class Vector4Frame extends JFrame implements ActionListener {
   JButton addint, addstr, dblit;
   JTextArea text;
   int i;
   Vector <I> v;
   
   public Vector4Frame () {
      setLayout(new BorderLayout());
      JPanel p = new JPanel();
      p.setLayout(new FlowLayout());
      p.add(addint = new JButton("Add int"));
      p.add(new JLabel("  "));
      p.add(addstr = new JButton("Add string"));
      p.add(new JLabel("  "));
      p.add(dblit = new JButton("Double Last"));
      add("South", p);
      add("Center", new JScrollPane(text = new JTextArea()));
      text.setFont(new Font("TimesRoman", Font.PLAIN, 20));
      addint.addActionListener(this);
      addstr.addActionListener(this);
      dblit.addActionListener(this);
      v = new Vector <I> ();
   }

   public void actionPerformed (ActionEvent evt) {
      if (evt.getSource() == addint) {
         v.add(new A4(i++));
      } else if (evt.getSource() == addstr) {
         v.add(new B4(String.valueOf(i++)));
      } else if (evt.getSource() == dblit) {
	 try {
	    A4 f = (A4)v.lastElement();
	    v.add(new A4(f.answer()));
            v.add(new A4(v.lastElement().dbl()));
	 } catch (Exception e) { 
	    StackTraceElement[] s = e.getStackTrace();
	    try {
	       for (int i=0 ; i < 40 ; i++)
		  text.append(s[i].toString()+"\n");
	    }  catch (Exception f) { }
	 }
      }
      text.append(v.toString()+"\n");
   }
}

public class typ_unsafe_1 extends Applet implements ActionListener {
   JButton go;
   
   public void init () {
      setLayout(new BorderLayout());
      add("Center", go = new JButton("Applet"));
      go.addActionListener(this);
   }

   public void actionPerformed (ActionEvent evt) {
      Vector4Frame af = new Vector4Frame();
      af.setSize(800,500);
      af.setVisible(true);
   }
}
