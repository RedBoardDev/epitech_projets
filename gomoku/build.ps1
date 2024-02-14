if (Test-Path -Path "build") {
    Remove-Item -Path "build" -Recurse -Force
    Write-Output "Le dossier 'build' et son contenu ont été supprimés."
} else {
    Write-Output "Le dossier 'build' n'existe pas, aucune action requise."
}
New-Item -ItemType Directory -Name "build"
Set-Location "build"
Invoke-Expression "cmake .."
try {
    Invoke-Expression "msbuild .\pbrain-gomoku-ai.vcxproj /p:Configuration=Release"
    Remove-Item -Path "..\pbrain-gomoku-ai.exe"
    Move-Item -Path ".\Release\pbrain-gomoku-ai.exe" -Destination "..\pbrain-gomoku-ai.exe"
} catch {
    Invoke-Expression "./pbrain-gomoku-ai.sln"
}

Set-Location ".."
