// appPlayerInfo
package main

import (
	"fmt"
	"internal/syscall/windows/registry"
	_ "io/ioutil"
	"log"
	"os"
	"strings"
)

func GetFilePath(sPath string) string {

	Index := strings.LastIndex(sPath, "\\")
	return sPath[0:Index]
}

func GetMOMODataInfo(skey string) (string, error) {

	key, err := registry.OpenKey(registry.CURRENT_USER, "SOFTWARE\\NOXGAMES\\MOMO", registry.QUERY_VALUE)
	if err != nil {
		log.Fatal(err)
	}
	defer key.Close()

	val, _, err := key.GetStringValue(skey)
	if err != nil {
		log.Fatal(err)
		return "", err
	}

	return val, nil
}

func Rundnplayer() bool {

	InstallDir, _ := GetMOMODataInfo("InstallDir")
	sRunApp := fmt.Sprintf("%s\\dnplayer.exe", InstallDir)

	_, err := os.Stat(sRunApp)
	if err != nil {
		return false
	}

	attr := &os.ProcAttr{Files: []*os.File{nil, nil, nil}}
	proc, runerr := os.StartProcess(sRunApp, []string{}, attr)
	if runerr != nil {
		log.Fatalln(runerr)
	}

	log.Println(proc.Pid)

	return true
}

func GetNoxDataInfo(skey string) (string, error) {

	key, err := registry.OpenKey(registry.LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Nox", registry.QUERY_VALUE)
	if err != nil {
		log.Fatal(err)
	}
	defer key.Close()

	val, _, err := key.GetStringValue(skey)
	if err != nil {
		log.Fatal(err)
		return "", err
	}
	return val, nil
}

func RunNoxplayer() bool {

	InstallDir, _ := GetNoxDataInfo("UninstallString")
	sRunApp := fmt.Sprintf("%s\\Nox.exe", GetFilePath(InstallDir))

	_, err := os.Stat(sRunApp)
	if err != nil {
		return false
	}

	attr := &os.ProcAttr{Files: []*os.File{nil, nil, nil}}
	proc, runerr := os.StartProcess(sRunApp, []string{}, attr)
	if runerr != nil {
		log.Fatalln(runerr)
	}

	log.Println(proc.Pid)

	return true
}

func GetMEmuDataInfo(skey string) (string, error) {

	key, err := registry.OpenKey(registry.LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\MEmu", registry.QUERY_VALUE)
	if err != nil {
		log.Fatal(err)
	}
	defer key.Close()

	val, _, err := key.GetStringValue(skey)
	if err != nil {
		log.Fatal(err)
		return "", err
	}

	return val, nil
}

func RunMEmuplayer() bool {

	InstallDir, _ := GetMEmuDataInfo("InstallLocation")
	sRunApp := fmt.Sprintf("%s\\MEmu\\MEmuConsole.exe", InstallDir)
	//fmt.Println(sRunApp)

	_, err := os.Stat(sRunApp)
	if err != nil {
		return false
	}

	attr := &os.ProcAttr{Files: []*os.File{nil, nil, nil}}
	proc, runerr := os.StartProcess(sRunApp, []string{sRunApp, "MEmu", "", "", ""}, attr)

	if runerr != nil {
		log.Fatalln(runerr)
	}

	log.Println(proc.Pid)

	return true
}

func main() {

	//[MOMO]앱플레이어
	//Rundnplayer()

	//[Nox]앱플레이어
	//RunNoxplayer()

	//[MEmu]앱플레이어
	RunMEmuplayer()
}
