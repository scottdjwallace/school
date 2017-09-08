using UnityEngine;
using System.Collections;

public class menu : MonoBehaviour {

	// Use this for initialization

	public Texture2D texture1;
	public Texture2D texture1Dark = null;
	public Rect StartButtonRect;

	GUIStyle startStyle;
	void Start () {
		StartButtonRect = new Rect(Screen.width/2 + texture1.width/5,Screen.height - texture1.height/2,texture1.width/3,texture1.height/3);
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnGUI()
	{
		if (StartButtonRect.Contains (Event.current.mousePosition)) {
			GUI.DrawTexture (StartButtonRect, texture1Dark);
		} else {
			GUI.DrawTexture (StartButtonRect, texture1);
		}
		if(GUI.Button(StartButtonRect, "", new GUIStyle())) {
			Application.LoadLevel("Level1");
		}
	}


}
