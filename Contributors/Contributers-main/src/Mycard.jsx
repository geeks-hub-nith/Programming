import React from "react";
import { Card, Button } from "react-bootstrap";
import {
  MDBCard,
  MDBCardBody,
  MDBCardTitle,
  MDBCardText,
  MDBCardImage,
  MDBBtn,
  MDBRipple
} from "mdb-react-ui-kit";

export function Mycard1(props) {
  return (
    <div>
      <Card border="warning">
        <Card.Header
          contentEditable="true"
          style={{ background: "yellow", opacity: "1" }}
        >
          {props.name}
        </Card.Header>
        <Card.Body>
          <Card.Title contentEditable="true">Info Card Title</Card.Title>
          <Card.Text contentEditable="true">
            Some quick example text to build on the card title and make up the
            bulk of the card's content.
          </Card.Text>
        </Card.Body>
      </Card>
    </div>
  );
}

export function Mycard2(props) {
  return (
    <MDBCard style={{ maxWidth: "22rem" }}>
      <MDBRipple
        rippleColor="light"
        rippleTag="div"
        className="bg-image hover-overlay"
      >
        <a href={props.html_url}>
          <MDBCardImage
            src={props.avatar}
            fluid
            href="https://www.google.com"
          />
        </a>
        <div
          className="mask"
          style={{ backgroundColor: "rgba(251, 251, 251, 0.15)" }}
        ></div>
      </MDBRipple>

      <MDBCardBody>
        <MDBCardTitle>{props.name}</MDBCardTitle>

        <MDBCardText>Contributions : {props.contributions}</MDBCardText>
        <MDBBtn href="#">Button</MDBBtn>
      </MDBCardBody>
    </MDBCard>
  );
}

export default function Mycard(props) {
  return (
    <div className="card">
      <Card style={{ maxWidth: "22rem" }}>
        <a href={props.html_url}>
          <Card.Img variant="top" src={props.avatar} />
        </a>
        <Card.Body>
          <Card.Title>{props.name}</Card.Title>
          <Card.Text>Contributions : {props.contributions}</Card.Text>
          <Button variant="primary" href="{props.html_url}">
            Github
          </Button>
        </Card.Body>
      </Card>
    </div>
  );
}
