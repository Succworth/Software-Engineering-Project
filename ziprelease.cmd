@echo off
pushd "%~dp0"
powershell Compress-7Zip "Software-Engineering-Project\release" -ArchiveFileName "SampleX64.zip" -Format Zip
:exit
popd
@echo on