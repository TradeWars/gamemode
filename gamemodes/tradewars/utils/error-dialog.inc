// for displaying the current error stack to a player via dialog.

static errors[2048];

stock ShowErrorDialog(playerid) {
	if(GetErrorCount() == 0) {
		return;
	}

	GetErrors(errors);
	Dialog_Open(
		playerid,
		"",
		DIALOG_STYLE_MSGBOX,
		"Errors",
		errors,
		"Close",
		""
	);

	return;
}
