#pragma once
namespace Indexes {
	enum tabWidgetIndex
	{
		tabBackup,
		tabRecovery,
		tabStatus
	};
	enum tableColumn
	{
		Title,
		Path,
		Time,
		Select
	};
	enum backupType
	{
		NOTFOUND = -1,
		SYSTEM = -2,
		VOLUME = -3,
		FILE = -4

	};
	enum backupPeriod
	{
		ONCE = -2,
		Periodic = -3
	};

	/*std::map<tableColumn,std::string> column;
	column[Title] = "Title";
	column[Path] = "Path";
	column[Time]= "Time";
	column[Select] = "Select";
	*/
}