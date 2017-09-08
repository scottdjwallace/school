using UnityEngine;
using System.Collections;

public class StartMenuScript : MonoBehaviour {

	public Texture2D texture1 = null;
	public Texture2D texture2 = null;

	public Texture2D texture1Dark = null;
	public Texture2D texture2Dark = null;

	public Rect StartButtonRect;
	public Rect RulesButtonRect;


	void Start(){
		StartButtonRect = new Rect(Screen.width/2 - texture1.width/4 , Screen.height/2,texture1.width/2,texture1.height/2);
		//StartButtonDarkRect = new Rect(462, 576-378,texture2.width/2,texture2.height/2);
		RulesButtonRect = new Rect (Screen.width/2 - texture2.width/4,Screen.height/2 + texture2.height/2, texture2.width/2,texture2.height/2);
	}

	void OnGUI () {
		//StartButton = new Rect(Screen.width/2-50,Screen.height/2+90,texture1.width/2,texture1.height/2);
		

//MISSING THE TITLE OF THE GAME

		if (StartButtonRect.Contains (Event.current.mousePosition))
		{
			GUI.DrawTexture(StartButtonRect , texture1Dark);
			GUI.DrawTexture(RulesButtonRect , texture2);
		}
		else if (RulesButtonRect.Contains (Event.current.mousePosition))
		{
			GUI.DrawTexture(StartButtonRect , texture1);
			GUI.DrawTexture(RulesButtonRect , texture2Dark);
		}
		else
		{
			GUI.DrawTexture(StartButtonRect , texture1);		
			GUI.DrawTexture(RulesButtonRect , texture2);
		}

		if(GUI.Button(StartButtonRect, "", new GUIStyle())) {
			Application.LoadLevel("Level1");
		}
		
		if(GUI.Button(RulesButtonRect, "", new GUIStyle())) {
			Application.LoadLevel("Instruction");
		}
	}
}
