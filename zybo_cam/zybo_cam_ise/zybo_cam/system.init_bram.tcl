cd /tp/xph3sle/xph3sle512/ProjetSLE_bis/zybo_cam/zybo_simple
if { [ catch { xload xmp system.xmp } result ] } {
  exit 10
}

if { [catch {run init_bram} result] } {
  exit -1
}

exit 0
