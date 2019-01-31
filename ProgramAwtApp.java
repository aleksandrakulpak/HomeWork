(WindowEvent e){};
    public void windowIconified(WindowEvent e){};
    public void windowDeiconified(WindowEvent e){};
    public void windowActivated(WindowEvent e){};
    public void windowDeactivated(WindowEvent e){};

    public void paint(Graphics g){

        Dimension rc=getSize();
        Insets in=getInsets();

        int RH=rc.width;
        int RW=rc.height;

        int minX=in.left; int maxX=RH-in.right;
        int minY=in.top;  int maxY=RW-in.bottom;

        int cx,cy,dx,dy;

        cx=Math.abs(maxX-minX)/2;
        cy=Math.abs(maxY-minY)/2;
        dx=maxX/10;
        dy=maxY/10;

        g.setColor(new Color(0x8F46C8));
        String txt="Програмування графічними примітивами: ";
        g.setFont(new Font("Trebuchet Ms",Font.PLAIN,24));
        int nf=g.getFontMetrics().stringWidth(txt);
        g.drawString(txt,nf/2-220,nf/2-180);


        int x1,y1,x2,y2;

        Graphics2D g2=(Graphics2D) g;
        g2.setStroke(new BasicStroke(3.0f));


        // TO DO

        x1=120; y1=80; int d=500; dx=dy=18;
        g.setColor(new Color(0x103610));
        for (int i = 0; i <19 ; i++) {
            g.drawRect(x1,y1,d,d);x1+=dx; y1+=dy;d-=2*dx;
        }

        //TimeUnit.MILLISECONDS.sleep(50);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        g.setColor(new Color(0xFFFFFF));
        g.fillRect(0,0,RH,RW);

        x1=120; y1=80; d=500; dx=dy=18;
        g.setColor(new Color(0x103610));
        for (int i = 0; i <19 ; i++) {
            g.drawOval(x1,y1,d,d);x1+=dx; y1+=dy;d-=2*dx;
        }

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        g.setColor(new Color(0xFFFFFF));
        g.fillRect(0,0,RH,RW);

        x1=120; y1=80; d=130; dx=dy=25;
        g.setColor(new Color(0x103610));
        for (int i = 0; i <4 ; i++) {
            x1=120;
            for (int j = 0; j <5 ; j++){
                g.drawOval(x1,y1,d,d);
                x1+=d-dx;
            }
            y1+=d-dy;

        }

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        g.setColor(new Color(0xFFFFFF));
        g.fillRect(0,0,RH,RW);

        x1=120; y1=80; d=130; dx=dy=20;
        g.setColor(new Color(0x103610));
        for (int i = 0; i <3; i++) {
            x1=120;
            for (int j = 0; j <4 ; j++) {
                g.drawRect(x1,y1,d,d);
                x1+=d+dx;
            }
            y1+=d+dy;
        }

        x1=195; y1=150; d=130; dx=dy=20;
        for (int i = 0; i <2; i++) {
            x1=195;
            for (int j = 0; j <3 ; j++) {
                g.drawRect(x1,y1,d,d);
                x1+=d+dx;
            }
            y1+=d+dy;
        }


    }
    public GrLibrary(){
        super("Графічні примітиви.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
    public static void main(String[] args) {
        new GrLibrary();
    }

}
