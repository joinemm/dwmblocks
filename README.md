# dwmblocks

My fork of dwmblocks status bar.

Includes two block configurations, one for desktop and one for laptop.
The desktop version does not include common laptop functions such as battery or wifi.
The version to build is determined by the `VERSION` environment variable at compile time.

Valid values for `VERSION` are `laptop` and `desktop`. If not provided, defaults to `laptop`

## Installing

```
$ sudo make clean install VERSION=laptop
$ dwmblocks &
```
