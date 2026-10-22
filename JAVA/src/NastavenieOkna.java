import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;

import javax.swing.JFrame;

public class NastavenieOkna extends JFrame {
	protected GridBagConstraints gbc;

	public NastavenieOkna() {
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(500,500);
		setLayout(new GridBagLayout());
		gbc = new GridBagConstraints();
		
	}
	
	public static void main(String[] args) {
		new NastavenieOkna();
	}

}
