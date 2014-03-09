using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Main
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        BackEnd.ManagedModel model;

        public MainWindow()
        {
            InitializeComponent();
            model = new BackEnd.ManagedModel();
            model.startNewGame();
            startNewGame();
            showInstructions();
        }

        private static void showInstructions()
        {
            MessageBox.Show(Properties.Resources.rulesMessage, Properties.Resources.emilyMessageTitle);
        }

        private int getCurrentNumber()
        {
            return model.getCurrentNumber();
        }

        private int getYourWins()
        {
            return model.getYourWins();
        }

        private int getEmilysWins()
        {
            return model.getEmilysWins();
        }

        private int getTotalWins()
        {
            return model.getTotalWins();
        }

        private int raiseCurrentNumber(int amount)
        {
            return model.raiseCurrentNumber(amount);
        }

        private void startNewGame()
        {
            YouWinsTextBlock.Text = "Your wins:\t" + getYourWins();
            EmilyWinsTextBlock.Text = "Emily's wins:\t" + getEmilysWins();
            TotalWinsTextBlock.Text = "Total wins:\t" + getTotalWins();
            EmilyImage.Content = FindResource("EmilyNormal");
            enableUserChoiceButtons();
        }

        private void enableUserChoiceButtons()
        {
            currentNumberTextBlock.Text = getCurrentNumber().ToString(CultureInfo.CurrentCulture);
            EmilyImage.Content = FindResource("EmilyNormal");
            UserChoice1Button.Content = getCurrentNumber() + 1;
            UserChoice1Button.IsEnabled = true;
            if (getCurrentNumber() >= 20)
            {
                UserChoice2Button.Content = "";
                UserChoice3Button.Content = "";
            }
            else
            {
                UserChoice2Button.Content = getCurrentNumber() + 2;
                UserChoice2Button.IsEnabled = true;
                if (getCurrentNumber() >= 19)
                {
                    UserChoice3Button.Content = "";
                }
                else
                {
                    UserChoice3Button.Content = getCurrentNumber() + 3;
                    UserChoice3Button.IsEnabled = true;
                }
            }
        }

        async private void updateOpponent(int status)
        {
            //Check if lost.
            if (status == -2)
            {
                EmilyImage.Content = FindResource("EmilyWinner");
                await Task.Delay(512);
                MessageBox.Show(Properties.Resources.youLose, Properties.Resources.emilyMessageTitle);
                startNewGame();
            }
            else
            {
                //Lock buttons.
                UserChoice1Button.IsEnabled = false;
                UserChoice2Button.IsEnabled = false;
                UserChoice3Button.IsEnabled = false;
                //Opponent's turn.
                OpponentsTurnTextBlock.Visibility = System.Windows.Visibility.Visible;
                //Wait.
                EmilyImage.Content = FindResource("EmilyThinking");
                await Task.Delay(2048);
                //End move.
                OpponentsTurnTextBlock.Visibility = System.Windows.Visibility.Hidden;
                if (status == -3)
                {
                    currentNumberTextBlock.Text = "21";
                    EmilyImage.Content = FindResource("EmilyLoser");
                    await Task.Delay(512);
                    MessageBox.Show(Properties.Resources.youWin, Properties.Resources.emilyMessageTitle);
                    startNewGame();
                }
                else
                {
                    //Unlock Buttons
                    enableUserChoiceButtons();
                }
            }
        }

        private void NewGameMenuItem_Click(object sender, RoutedEventArgs e)
        {
            model.startNewGame();
            startNewGame();
        }

        private void InstructionsMenuItem_Click(object sender, RoutedEventArgs e)
        {
            showInstructions();
        }

        private void CreditsMenuItem_Click(object sender, RoutedEventArgs e)
        {
			MessageBox.Show(Properties.Resources.creditsMessageBody, Properties.Resources.creditsMessageTitle);
        }

        private void ExitMenuItem_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void UserChoice1Button_Click(object sender, RoutedEventArgs e)
        {
            currentNumberTextBlock.Text = (getCurrentNumber() + 1).ToString(CultureInfo.CurrentCulture);
            updateOpponent(raiseCurrentNumber(1));
        }

        private void UserChoice2Button_Click(object sender, RoutedEventArgs e)
        {
            currentNumberTextBlock.Text = (getCurrentNumber() + 2).ToString(CultureInfo.CurrentCulture);
            updateOpponent(raiseCurrentNumber(2));
        }

        private void UserChoice3Button_Click(object sender, RoutedEventArgs e)
        {
            currentNumberTextBlock.Text = (getCurrentNumber() + 3).ToString(CultureInfo.CurrentCulture);
            updateOpponent(raiseCurrentNumber(3));
        }

        private void HardMode_Click(object sender, RoutedEventArgs e)
        {
            if (model.isInHardMode())
            {
                model.setHardMode(false);
            }
            else
            {
                model.setHardMode(true);
            }
            startNewGame();
        }
    }
}
