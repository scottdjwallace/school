using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TicTacToe
{
    public partial class Form1 : Form
    {
        bool turn = true; // true = x turn. false = o turn
        int turn_count = 0; // ++ every move

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("By: Scott", "Tic Tac Toe About");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button_click(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            if (turn)
            {
                b.Text = "X";
            }
            else
            {
                b.Text = "O";
            }
            turn = !turn;
            turn_count++;
            b.Enabled = false;
            check_for_winner();
        }

        private void check_for_winner()
        {
            bool winner = false;

            // horizontal checks
            if ((A1.Text == A2.Text) && (A2.Text == A3.Text) && (!A1.Enabled)) winner = true;
            else if ((B1.Text == B2.Text) && (B2.Text == B3.Text) && (!B1.Enabled)) winner = true;
            else if ((C1.Text == C2.Text) && (C2.Text == C3.Text) && (!C1.Enabled)) winner = true;

            // vertical checks
            else if ((A1.Text == B1.Text) && (B1.Text == C1.Text) && (!A1.Enabled)) winner = true;
            else if ((A2.Text == B2.Text) && (B2.Text == C2.Text) && (!A2.Enabled)) winner = true;
            else if ((A3.Text == B3.Text) && (B3.Text == C3.Text) && (!A3.Enabled)) winner = true;

            // diagonal checks
            else if ((A1.Text == B2.Text) && (B2.Text == C3.Text) && (!A1.Enabled)) winner = true;
            else if ((A3.Text == B2.Text) && (B2.Text == C1.Text) && (!C1.Enabled)) winner = true;

            if (winner)
            {
                disable_buttons();
                String win = "";
                if (turn)
                {
                    win = "O";
                }
                else
                {
                    win = "X";
                }
                MessageBox.Show(win + " wins!", "Yay!");
            }
            else
            {
                if (turn_count == 9)
                {
                    MessageBox.Show("It's a draw!", "Bummer!");
                }
            }
        }

        private void disable_buttons()
        {
            try
            {
                foreach (Control c in Controls)
                {
                    Button b = (Button)c;
                    b.Enabled = false;
                }
            }
            catch {  }
        }

        private void newGameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // resest all buttons, turncoutn, and turn
            turn = true;
            turn_count = 0;
            try
            {
                foreach (Control c in Controls)
                {
                    Button b = (Button)c;
                    b.Enabled = true;
                    b.Text = "";
                }
            }
            catch { }
        }

        private void button_enter(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            if (b.Enabled)
            {
                if (turn)
                {
                    b.Text = "X";
                }
                else
                {
                    b.Text = "O";
                }
            }
        }

        private void button_leave(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            if (b.Enabled)
            {
                b.Text = "";
            }
        }

    }
}
