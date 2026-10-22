import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Hra_zivot extends NastavenieOkna implements ActionListener{

	private int Field_size;
	private JButton[][] matrix;
	private JPanel panel;
	private JButton start;
	private JButton stop;
	private JButton koniec;
	private Timer timer;
	private JButton click;
	private String[] suradnice;
	private int x;
	private int y;
	private int z;
	private int value;
	private Integer[][] matrixb;
	private ArrayList<Integer>list;
	
	public Hra_zivot(){
	
		
		Field_size = 25;
		matrix = new JButton [Field_size][Field_size];
		matrixb = new Integer [Field_size][Field_size];
		list =  new ArrayList<Integer>();

		
		
		
		for (int i = 0; i < Field_size; i++) {
			gbc.gridy = i;
			for (int j = 0; j < Field_size; j++) {
				gbc.gridx = j;
				matrix[i][j] = new JButton();
				matrix[i][j].setPreferredSize(new Dimension(500/Field_size, 500/Field_size));
				matrix[i][j].addActionListener(this);
				matrix[i][j].setBackground(Color.WHITE);
				matrix[i][j].setActionCommand(i+";"+j+";"+0);
				
				add(matrix[i][j],gbc);
			}
		}
		for (int i = 0; i < Field_size; i++) {
			for (int j = 0; j < Field_size; j++) {
				matrixb[i][j] = 0 ;
			}
		}
		panel = new JPanel();
		start = new JButton("Start");
		start.addActionListener(this);
		stop = new JButton("Stop");
		stop.addActionListener(this);
		koniec = new JButton("Koniec");
		koniec.addActionListener(this);
		panel.add(start);
		panel.add(stop);
		panel.add(koniec);
		gbc.gridwidth = Field_size;
		gbc.gridx = 0;
		gbc.gridy ++;
		
		add(panel,gbc);
		
		timer = new Timer(100,this);
		
		
		pack();
		setVisible(true);
	}
	public static void main(String[] args) {
		new Hra_zivot();
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource().equals(start)) {
			timer.start();
		}
		else if (e.getSource().equals(stop)) {
			timer.stop();
		}
		else if (e.getSource().equals(koniec)) {
			timer.stop();
			dispose();
		}
		else if (e.getSource()== timer) {
			for (int i = 1; i < Field_size-1; i++) {
				gbc.gridy = i;
				for (int j = 1; j < Field_size-1; j++) {	
					gbc.gridx = j;
					if (i >= Field_size) {
						value = get_z(i, j+1)+get_z(i-1, j)+get_z(i, j-1)+
							get_z(i-1, j-1)+get_z(i-1, j+1);
					}
					else if (i <= 0) {
						value = get_z(i+1, j)+get_z(i, j+1)+get_z(i, j-1)+
								get_z(i+1, j+1)+get_z(i+1, j-1);
					}
					else if (j >= Field_size) {
						value = get_z(i+1, j)+get_z(i-1, j)+get_z(i, j-1)+
								get_z(i-1, j-1)+get_z(i+1, j-1);
					}
					else if (j <= 0) {
						value = get_z(i+1, j)+get_z(i, j+1)+get_z(i-1, j)+
								get_z(i+1, j+1)+get_z(i-1, j+1);
					}
					else {
						value = get_z(i+1, j)+get_z(i, j+1)+get_z(i-1, j)+get_z(i, j-1)+
								get_z(i+1, j+1)+get_z(i-1, j-1)+get_z(i+1, j-1)+get_z(i-1, j+1);
					}
					
					if (value > 0) {
						System.out.println(value);
					}

					if (value < 2  & get_z(i, j) == 1) {
						matrixb[i][j] = 0;
					}
					else if (value > 1 & value <4 & get_z(i, j) == 1) {
						matrixb[i][j] = 1;
					}
					else if (value > 3 & get_z(i, j) == 1) {
						matrixb[i][j] = 0;
					}
					else if (value == 3 & get_z(i, j) == 0) {
						matrixb[i][j] = 1;
					}
					else {
						matrixb[i][j] = 0;
					}
//					if (get_z(i, j) == 1) {
//						if (value ==2 || value ==3) {
//							matrixb[i][j] = 1;
//						} else {
//							matrixb[i][j] = 0;
//						}
//					} else {
//						if (value == 3) {
//							matrixb[i][j] = 1;
//						} else {
//							matrixb[i][j] = 0;
//						}
//					}
					
					
					
				}
			} 
			
			
			
			for (int i = 0; i < Field_size; i++) {
				for (int j = 0; j < Field_size; j++) {
					matrix[i][j].setActionCommand(i+";"+j+";"+matrixb[i][j]);
					if (matrixb[i][j] == 0) {
						matrix[i][j].setBackground(Color.WHITE);
					}
					if (matrixb[i][j] == 1) {
						matrix[i][j].setBackground(Color.BLACK);
					}
				}
			}
		}
		
		
		
		else{
			click = (JButton)e.getSource();
			suradnice = click.getActionCommand().split(";");
			x = Integer.parseInt(suradnice[0]);
			y = Integer.parseInt(suradnice[1]);
			z = Integer.parseInt(suradnice[2]);
			if (z == 0) {
				z = 1;
				matrix[x][y].setBackground(Color.BLACK);
			}
			else {
				z = 0;
				matrix[x][y].setBackground(Color.WHITE);
			}
			matrix[x][y].setActionCommand(x+";"+y+";"+z);
		}
		
		repaint();
		
	}
	private int get_z(int i, int j) {
		suradnice = matrix[i][j].getActionCommand().split(";");
		z = Integer.parseInt(suradnice[2]);
//		if (z == 1) {
//			System.out.println(z);
//		}
		return(z);
		
	}

}
