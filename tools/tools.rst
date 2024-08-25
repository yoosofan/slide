cd 02/cpp/
7z e poshtiban-moodle2-course-8885-برنامه‌سازی_پیشرفته_کد_211714__گروه_1_\(14002\)-14010615-1742-nu.mbz 

https://fileinfo.com/extension/mbz
Since MBZ files are simply renamed .ZIP files, you can extract the contents in the archives by renaming the .mbz file extension to .zip. Then, extract the contents using a Zip-decompression utility, such as Corel WinZip or Apple Archive Utility. After extracting the contents, change the .zip file extension back to .mbz.

------------

https://moodle.org/mod/forum/discuss.php?d=350148

After you rename and unzip the backup file into its folder, first open up the main file moodle_backup.xml. That's the master file for the backup.

In that file in the section for <activities>, you will find a list of all the modules in the course. Look for the type and title of the modules you want. Note the <moduleid> number for each of those.

Armed with the module id, then go into the /activities folder where you will see a subfolder for each activity listed by type_moduleid, for example forum_173, label_240, resource_496. In each folder is the data for each activity in the various xml files.

If you need to locate attached or embedded files for a particular activity, those are listed by file number in the inforef.xml for each activity. Using that file number look In the files.xml file in the main directory. You can  search for that file number by <file id="###"> to find its details. Use the content hash of the file (which is actually its filename) to then locate the file itself over in the /files folder.

https://www.umass.edu/it/support/moodle/moodle-mbz-backup-files