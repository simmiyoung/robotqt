**Scenario XML Pattern for RobotQt**

Felipe Ferreri Tonello <eu@felipetonello.com>

_Last Update: 27-06-2011_


# Scenario XML Pattern #

## Declaration: ##

```
<?xml version="1.0" encoding="UTF-8"?>
<scenario>
	<set ... />
	<size ... />
	<drawing>
		<...>
	</drawing>
</scenario>
```

  * Set tag
    * Attribute:
      * attribute's\_name
        * Ex: `<set name="My Scenario" />`

  * Size tag
    * Required
    * Attribute:
      * width
      * height

  * Drawing tag
    * Required, but it can be blank
    * Drawing is ordered straight forward according to the list
    * Elements:
      * rect
        * Attribute:
          * x
          * y
          * width
          * height
          * color: RGB eg. #FF00BB
      * line
        * Attribute:
          * x1
          * y1
          * x2
          * y2
          * color: RGB eg. #FF00BB
      * ellipse
        * Attribute:
          * x
          * y
          * width
          * height
          * color: RGB eg. #FF00BB

