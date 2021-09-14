// Chapter 12
// TestPanels.java
// August 7, 2016


package chapter12;

import java.awt.*;
import javax.swing.*;


public class TestPanels extends JFrame {
	public TestPanels() {
		JPanel p1 = new JPanel();
		p1.setLayout(new GridLayout(4, 3));
		
		for (int i = 1; i <= 9; i++) {
			p1.add(new JButton("" + i));
		}

		p1.add(new JButton("" + 0));
		p1.add(new JButton("Start"));
		p1.add(new JButton("Stop"));
		
		JPanel p2 = new JPanel(new BorderLayout());
		p2.add(new JTextField("Time to be displayed here"), BorderLayout.NORTH);
		p2.add(p1, BorderLayout.CENTER);
		
		add(p2, BorderLayout.EAST);
		add(new JButton("Food to be placed here"), BorderLayout.CENTER);
	
	}
	
	public static void main(String[] args) {
		TestPanels frame = new TestPanels();
		frame.setTitle("TheFrontViewOfAMicrowaveOven");
		frame.setSize(400, 250);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
