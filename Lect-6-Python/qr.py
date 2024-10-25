import qrcode

img = qrcode.make('https://www.youtube.com/watch?v=aHaOIvR00So')
img.save('qr.png', 'PNG')
