import java.applet.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

/* <applet code=typ_safe_1.class width=90 height=22></applet> */

interface I {
   public int dbl ();
}

class A implements I {
   int number;
   
   public A (int n) { number = n; }
   public int dbl () { return number*2; }
   public String toString () { return String.valueOf(number); }
}

class B implements I {
   String str;
   
   public B (String n) { str = n; }
   public int dbl () { return 2*Integer.parseInt(str); }
   public String toString () { return str; }
}

// A Vector can hold different kinds of objects
// But then operating on an object taken from the vector
// may be problematic if the operation does not apply to
// the type of object.  In this example, the vector 
// is defined to hold only I objects and all I objects
// implement method dbl which returns an int.
class Vector3Frame extends JFrame implements ActionListener {
   JButton addint, addstr, dblit;
   JTextArea text;
   int i;
   Vector <I> v;
   
   public Vector3Frame () {
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
      if (evt.getSource() == addint) v.add(new A(i++));
      else if (evt.getSource() == addstr) v.add(new B(String.valueOf(i++)));
      else if (evt.getSource() == dblit) {
	 try {
            v.add(new A(v.lastElement().dbl()));
         } catch (Exception e) { 
            text.append("You're crazy\n");
         }
      }
      text.append(v.toString()+"\n");
   }
}

public class typ_safe_1 extends Applet implements ActionListener {
   JButton go;
   
   public void init () {
      setLayout(new BorderLayout());
      add("Center", go = new JButton("Applet"));
      go.addActionListener(this);
   }

   public void actionPerformed (ActionEvent evt) {
      Vector3Frame af = new Vector3Frame();
      af.setSize(800,300);
      af.setVisible(true);
   }
}
