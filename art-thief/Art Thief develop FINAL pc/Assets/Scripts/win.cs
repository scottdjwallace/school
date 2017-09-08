using UnityEngine;
using System.Collections;

public class win : MonoBehaviour {

	
	public Texture2D texture1;
	public Texture2D texture1Dark = null;
	public Rect StartButtonRect;
	
	GUIStyle startStyle;
	void Start () {
		StartButtonRect = new Rect (Screen.width/2 - texture1.width/4,Screen.height/2+100, texture1.width/2,texture1.height/2);
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
			globalproperties.LevelTime = 120;
			Application.LoadLevel("menu");
		}
	}
}
