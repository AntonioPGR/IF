# run.ps1
param (
  [string]$name
)

$fileBaseName = [System.IO.Path]::GetFileNameWithoutExtension($name)
$executableName = "$fileBaseName.exe"
g++ $name -o $executableName
& .\$executableName
Remove-Item $executableName -Force
