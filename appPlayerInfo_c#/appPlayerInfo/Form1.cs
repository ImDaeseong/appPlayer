using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace appPlayerInfo
{
    public partial class Form1 : Form
    {
        clsPlayerinfo clsPlayer = clsPlayerinfo.getInstance;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            clsPlayer.Rundnplayer();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            clsPlayer.RunNoxplayer();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            clsPlayer.RunMEmuplayer();
        }

    }
}
